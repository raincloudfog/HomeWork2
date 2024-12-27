#pragma once

#include <iostream>
#include <memory>

using namespace std;


template<typename T>
class HomeWork_1
{

public:
	//초기값 5이지만 count값으로 변경해서 사용 가능 하게 할 것
	//배열을 받겠다고 유니크 포인터저장
	unique_ptr<T[]> arr;


	//HomeWork_1<T>() {
		//if (arr == nullptr)
		//{
			//cout << "arr == nullptr" << endl;
		//}
	//}

#pragma region  이상한 출력 값 발견
	//void Push() {
	   // /* 이상한 출력
	   // * 해당 i  : 0
	   //	1.1
	   //	현재 i : 0
	   //	해당 i  : 1
	   //	해당 변수에 맞는 값을입력하세요.
	   //	현재 i : 0
	   //	해당 i  : 1

	   //	어째서 cin fail()이 다음 반복문에서 캐치되는지 이해 불가
	   //	int에서
	   //	1.1 입력했으면 바로 오류 뜰줄 알았는데 왜 다음에서 뜨는거지
	   // */


	   // std::cout << "정수를 입력하세요: ";
	   // cin >> count;

	   // cout << arr << endl;

	   // //초기화 해줌
	   // arr.reset();
	   // arr = make_unique<T[]>(count);


	   // //와일문도 가능하지만 시도 해보고 싶었습니다. i--; 를 
	   // for (int i = 0; i < count; i++)
	   // {
	   //	 cout << "해당 i  : " << i << endl;


	   //	 T num;
	   //	 cin >> num;
	   //	 if (cin.fail())
	   //	 {
	   //		 cout << "해당 변수에 맞는 값을입력하세요." << endl;
	   //		 cin.clear(); // 초기화
	   //		 cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	   //		 --i;
	   //		 continue;
	   //	 }
	   //	 else {
	   //		 arr[i] = num;

	   //	 }
	   //	 cout << "현재 i : " << i << endl;
	   // }
	//}
#pragma endregion



	void Push() {
		/* 이상한 출력
		* 해당 i  : 0
		   1.1
		   현재 i : 0
		   해당 i  : 1
		   해당 변수에 맞는 값을입력하세요.
		   현재 i : 0
		   해당 i  : 1

		   어째서 cin fail()이 다음 반복문에서 캐치되는지 이해 불가
		   int에서
		   1.1 입력했으면 바로 오류 뜰줄 알았는데 왜 다음에서 뜨는거지
		*/


		std::cout << "정수를 입력하세요: ";
		cin >> count;

		//cout << arr << endl;

		//초기화 해줌
		arr.reset();
		arr = make_unique<T[]>(count);


		//와일문도 가능하지만 시도 해보고 싶었습니다. i--; 를 
		for (int i = 0; i < count;)
		{
			cout << "해당 i  : " << i << endl;


			T num;
			cin >> num;
			if (cin.fail())
			{
				cout << "해당 변수에 맞는 값을입력하세요." << endl;
				cin.clear(); // 초기화
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else {
				arr[i] = num;
				i++;

			}
			//cout << "현재 i : " << i << endl;
		}
	}

	//더하기 함수
	void Plus() {
		//만약 값이 없는데 추가했을경우
		if (arr == nullptr)
		{
			Push();
		}

		cout << "count : " << count << endl;

		total = 0;

		// 배열 안에 값을 더해주기 // 안되는 이유 내일 찾아보기
		/*for (T i : arr)
		{
			total += i;
		}*/
		for (int i = 0; i < count; i++)
		{
			total += arr[i];
		}

		cout << "합계 : " << total << endl;


	}
	//평균
	void average() {
		cout << "합계 : " << total << " 평균 : " << (float)total / count << endl;
		aver = (float)total / count;
	}

private:

	//배열 크기 조절
	int count;
	T  total;
	float aver;



};
