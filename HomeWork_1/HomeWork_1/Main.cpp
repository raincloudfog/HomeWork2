#include "CH_2_1_1.h"
#include "CH_2_1_2.h"

using namespace CH_2_1;


int main() {


#pragma region �ʼ� ����1

    cout << "\n\n\n�ʼ� ���� 1 \n\n\n";

    ////���ø� ����ؼ� int �� ����������ϴ�.
    HomeWork_1<int>* work_1 = new HomeWork_1<int>;

    work_1->Push();
    work_1->Plus();
    work_1->average();

    //HomeWork_1<float>* work_2 = new HomeWork_1<float>;

    //work_2->Push();
    //work_2->Plus();
    //work_2->average();

#pragma endregion


    cout << "\n\n\n���� ���� 2 \n\n\n";



   

    BasicSort<int>* st = new CH_2_1::_Sort();
    st->resetCount();
    st->Sort(1);


    cout << "\n\n\n��������\n\n\n";
    st->resetCount();
    st->Sort(2);


    cout << "\n\n\n�Ǽ� ����\n\n\n";
    BasicSort<double>* st2 = new Double_Sort();

    st2->resetCount();
    st2->Sort(1);

	return 0;
}