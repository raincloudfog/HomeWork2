#pragma once
#include <memory>
#include <iostream>
#include <vector>



namespace CH_2_1 {

	using namespace std;

	/* 중요!!! 클래스도 위에 만들어야 됨 
	* 
	* C#에서는  전체 프로그램의 범위 내에서 접근할 수 있지만
	* C++은 클래스를 사용하기 전에 반드시 그 클래스가 정의되어 있어야 하고 그렇지 않으면 컴파일 오류가 발생
	* 즉 push 클래스가 sort클래스보다 위에있어야함..
	*/

	//다 풀고 보니 정렬 알고리즘 봐도 된다고 한다 으아아어어

	//템플릿 복습 
	template<typename T>
	class Push {


	public:


		//solid 원칙 복습

		virtual void P(shared_ptr<T[]> arr, int size) = 0;
	};


	class IntArrPush : public CH_2_1::Push<int>
	{
	private:

		int size = 0;



	public:


		IntArrPush() {}

		void P(shared_ptr<int[]> arr, int size)  override
		{			


			for (int i = 0; i < size; i++)
			{
				int A;
				cout << "정수를 입력해주세요";
				cin >> A;

				//배열은 자체적으로 포인터와 비슷하다 생각해야됨 
				//*arr[i] = 주소가 아니라 값자체임 그러므로 포인터표시할 이유가없음.
				arr[i] = A;

			}

		}

	};

	class DoubleArrPush : public CH_2_1::Push<double>
	{
	private:

		int size = 0;


	public:


		DoubleArrPush() {}

		void P(shared_ptr<double[]> arr, int size)  override
		{


			for (int i = 0; i < size; i++)
			{
				double A;
				cout << "실수를 입력해주세요";
				cin >> A;

				//배열은 자체적으로 포인터와 비슷하다 생각해야됨 
				//*arr[i] = 주소가 아니라 값자체임 그러므로 포인터표시할 이유가없음.
				arr[i] = A;

			}

		}

	};



	template<typename T>
	class BasicSort {

	protected:

		// 주의!!!
		 // 기본적으로 nullptr로 초기화됨
		shared_ptr<T[]> numbers;
		int size = 0;

		//숫자 교환하는 함수를 빼서 Sort에서 불필요한 코드를 줄이기 + 클래스를 더 만들어야되는지 생각

		void changenum(T& num1, T& num2) {

			int temp = num1;
			num1 = num2;
			num2 = temp;
		}

	public :
		
		//초기화
		virtual void resetCount() = 0;
		//1이면 오름차순 2면 내림차순
		virtual void Sort(int intibool) = 0;
	};



	class _Sort : public BasicSort<int>{


		//입력한 숫자 배열을 정렬 하는 프로그램 구현

	public:

		//-1073741819 또는 0xc0000005 오류 코드는 일반적으로 **액세스 위반 (Access Violation)**을 나타냅니다
		//nullptr포인터로 접근하려 했을때  // 포인터 메모리가 없는상태일경우 1. 해제된 2. 널포인터 등
		//배열의 경계를 초과했을때
		//스택 메모리 초과

		_Sort() {			
		}

		void resetCount() {
			cout << "정수를 입력해주세요";

			cin >> size;

			//초기화 하는 동시에 포인터에 새로운 주소 값 전달
			numbers.reset(new int[size]);

			//중요!!! 스마트 포인터는 가지고 있는걸 대입으로 바꿀 수 없다. 쉐어 포인터에서 대입은 복사 일경우만
			// 사용된다!
			// numbers(new int[size]); 이미 nullptr을 가지고 있는 상태 
			unique_ptr<IntArrPush> test = make_unique<IntArrPush>();
			test->P(numbers, size);
		}

		


		//solid 원칙 사용해보기
		//추상화
		//virtual void Push() = 0;

		void Sort(int intibool) {

			//존재 의미 사라짐
			//unique_ptr<int[]> arr = make_unique<int[],0>(size);

			for (int i = 0; i < size; i++)
			{
				
					for (int j = i; j < size; j++)
					{
						//아래 주석은 고민 흔적 과 해설
						
						//만약 해당 번호의 인덱스 보다 나머지가 더 작을 경우 
						//해당 번호로 이동 
						//맨앞부터 비교하니까 0위치에 3을  5 2  4 1 랑 비교하면 
						// 5는 크니까 넘어가고 2는 작으니 교체
						// 2 5 3 4 1 -> 1 5 3 4 2  1이가장 작으니 교체할 수 있는게 없음
						// 1위치 1 3 5 4 2-> 1 3 5 4 2 -> 1 2 5 4 3 더이상 교체 할 게 없음
						// 2위치 1 2 4 5 3 -> 	1 2 3 5 4 교체 불가 사실 끝났다고 봐야됨
						// 3위치 1 2 3 4 5 바뀔 것 없어야됨					
						// 여기서 궁금한건 숫자 교환 함수에 값을 거꾸로하면 반대로 커지려나? //그건아니다 
						//changenum(numbers[j], numbers[i]); // 이거 아님 더미데이터
						// 일단 매개변수에서 받은 숫자가 1혹은 2면 그 옆에 조건 도 확인하는 함수
						if (intibool ==1 && numbers[i] > numbers[j])
						{							
							changenum(numbers[i], numbers[j]);
							
						}

						else if (intibool == 2 &&numbers[i] < numbers[j])
						{		
							changenum(numbers[i], numbers[j]);
						}
							
					}
			}

			std::string test = intibool == 1 ? "오름차순" : "내림차순";

			cout << test << endl;

			for (int i = 0 ; i < size ; i++)
			{
				cout << numbers[i] <<  " ";
			}
			cout << endl;

		}

		//여기서 고민 조건문을 사용해서 포문을 여러개를 사용할지 아니면 Sort와 reSort함수를 만들어서 
	};	


	class Double_Sort: public BasicSort<double> {




	public:

		Double_Sort() {


		}

		void resetCount() {
			cout << "정수를 입력해주세요";

			cin >> size;

			//초기화 하는 동시에 포인터에 새로운 주소 값 전달
			numbers.reset(new double[size]);

			//중요!!! 스마트 포인터는 가지고 있는걸 대입으로 바꿀 수 없다. 쉐어 포인터에서 대입은 복사 일경우만
			// 사용된다!
			// numbers(new int[size]); 이미 nullptr을 가지고 있는 상태 
			unique_ptr<DoubleArrPush> test = make_unique<DoubleArrPush>();
			test->P(numbers, size);
		}



		//solid 원칙 사용해보기
		//추상화
		//virtual void Push() = 0;

		void Sort(int intibool) {

			for (int i = 0; i < size; i++)
			{

				for (int j = i; j < size; j++)
				{
					
					if (intibool == 1 && numbers[i] > numbers[j])
					{
						
						changenum(numbers[i], numbers[j]);

					}

					else if (intibool == 2 && numbers[i] < numbers[j])
					{
						changenum(numbers[i], numbers[j]);

					}

				}
			}

			std::string test = intibool == 1 ? "오름차순" : "내림차순";

			cout << test << endl;

			for (int i = 0; i < size; i++)
			{
				cout << numbers[i] << " ";
			}
			cout << endl;

		}
	};



}

