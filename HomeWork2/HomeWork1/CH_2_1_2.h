#pragma once
#include <memory>
#include <iostream>
#include <vector>



namespace CH_2_1 {

	using namespace std;

	/* �߿�!!! Ŭ������ ���� ������ �� 
	* 
	* C#������  ��ü ���α׷��� ���� ������ ������ �� ������
	* C++�� Ŭ������ ����ϱ� ���� �ݵ�� �� Ŭ������ ���ǵǾ� �־�� �ϰ� �׷��� ������ ������ ������ �߻�
	* �� push Ŭ������ sortŬ�������� �����־����..
	*/

	//�� Ǯ�� ���� ���� �˰��� ���� �ȴٰ� �Ѵ� ���ƾƾ��

	//���ø� ���� 
	template<typename T>
	class Push {


	public:


		//solid ��Ģ ����

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
				cout << "������ �Է����ּ���";
				cin >> A;

				//�迭�� ��ü������ �����Ϳ� ����ϴ� �����ؾߵ� 
				//*arr[i] = �ּҰ� �ƴ϶� ����ü�� �׷��Ƿ� ������ǥ���� ����������.
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
				cout << "�Ǽ��� �Է����ּ���";
				cin >> A;

				//�迭�� ��ü������ �����Ϳ� ����ϴ� �����ؾߵ� 
				//*arr[i] = �ּҰ� �ƴ϶� ����ü�� �׷��Ƿ� ������ǥ���� ����������.
				arr[i] = A;

			}

		}

	};



	template<typename T>
	class BasicSort {

	protected:

		// ����!!!
		 // �⺻������ nullptr�� �ʱ�ȭ��
		shared_ptr<T[]> numbers;
		int size = 0;

		//���� ��ȯ�ϴ� �Լ��� ���� Sort���� ���ʿ��� �ڵ带 ���̱� + Ŭ������ �� �����ߵǴ��� ����

		void changenum(T& num1, T& num2) {

			int temp = num1;
			num1 = num2;
			num2 = temp;
		}

	public :
		
		//�ʱ�ȭ
		virtual void resetCount() = 0;
		//1�̸� �������� 2�� ��������
		virtual void Sort(int intibool) = 0;
	};



	class _Sort : public BasicSort<int>{


		//�Է��� ���� �迭�� ���� �ϴ� ���α׷� ����

	public:

		//-1073741819 �Ǵ� 0xc0000005 ���� �ڵ�� �Ϲ������� **�׼��� ���� (Access Violation)**�� ��Ÿ���ϴ�
		//nullptr�����ͷ� �����Ϸ� ������  // ������ �޸𸮰� ���»����ϰ�� 1. ������ 2. �������� ��
		//�迭�� ��踦 �ʰ�������
		//���� �޸� �ʰ�

		_Sort() {			
		}

		void resetCount() {
			cout << "������ �Է����ּ���";

			cin >> size;

			//�ʱ�ȭ �ϴ� ���ÿ� �����Ϳ� ���ο� �ּ� �� ����
			numbers.reset(new int[size]);

			//�߿�!!! ����Ʈ �����ʹ� ������ �ִ°� �������� �ٲ� �� ����. ���� �����Ϳ��� ������ ���� �ϰ�츸
			// ���ȴ�!
			// numbers(new int[size]); �̹� nullptr�� ������ �ִ� ���� 
			unique_ptr<IntArrPush> test = make_unique<IntArrPush>();
			test->P(numbers, size);
		}

		


		//solid ��Ģ ����غ���
		//�߻�ȭ
		//virtual void Push() = 0;

		void Sort(int intibool) {

			//���� �ǹ� �����
			//unique_ptr<int[]> arr = make_unique<int[],0>(size);

			for (int i = 0; i < size; i++)
			{
				
					for (int j = i; j < size; j++)
					{
						//�Ʒ� �ּ��� ��� ���� �� �ؼ�
						
						//���� �ش� ��ȣ�� �ε��� ���� �������� �� ���� ��� 
						//�ش� ��ȣ�� �̵� 
						//�Ǿպ��� ���ϴϱ� 0��ġ�� 3��  5 2  4 1 �� ���ϸ� 
						// 5�� ũ�ϱ� �Ѿ�� 2�� ������ ��ü
						// 2 5 3 4 1 -> 1 5 3 4 2  1�̰��� ������ ��ü�� �� �ִ°� ����
						// 1��ġ 1 3 5 4 2-> 1 3 5 4 2 -> 1 2 5 4 3 ���̻� ��ü �� �� ����
						// 2��ġ 1 2 4 5 3 -> 	1 2 3 5 4 ��ü �Ұ� ��� �����ٰ� ���ߵ�
						// 3��ġ 1 2 3 4 5 �ٲ� �� ����ߵ�					
						// ���⼭ �ñ��Ѱ� ���� ��ȯ �Լ��� ���� �Ųٷ��ϸ� �ݴ�� Ŀ������? //�װǾƴϴ� 
						//changenum(numbers[j], numbers[i]); // �̰� �ƴ� ���̵�����
						// �ϴ� �Ű��������� ���� ���ڰ� 1Ȥ�� 2�� �� ���� ���� �� Ȯ���ϴ� �Լ�
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

			std::string test = intibool == 1 ? "��������" : "��������";

			cout << test << endl;

			for (int i = 0 ; i < size ; i++)
			{
				cout << numbers[i] <<  " ";
			}
			cout << endl;

		}

		//���⼭ ��� ���ǹ��� ����ؼ� ������ �������� ������� �ƴϸ� Sort�� reSort�Լ��� ���� 
	};	


	class Double_Sort: public BasicSort<double> {




	public:

		Double_Sort() {


		}

		void resetCount() {
			cout << "������ �Է����ּ���";

			cin >> size;

			//�ʱ�ȭ �ϴ� ���ÿ� �����Ϳ� ���ο� �ּ� �� ����
			numbers.reset(new double[size]);

			//�߿�!!! ����Ʈ �����ʹ� ������ �ִ°� �������� �ٲ� �� ����. ���� �����Ϳ��� ������ ���� �ϰ�츸
			// ���ȴ�!
			// numbers(new int[size]); �̹� nullptr�� ������ �ִ� ���� 
			unique_ptr<DoubleArrPush> test = make_unique<DoubleArrPush>();
			test->P(numbers, size);
		}



		//solid ��Ģ ����غ���
		//�߻�ȭ
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

			std::string test = intibool == 1 ? "��������" : "��������";

			cout << test << endl;

			for (int i = 0; i < size; i++)
			{
				cout << numbers[i] << " ";
			}
			cout << endl;

		}
	};



}

