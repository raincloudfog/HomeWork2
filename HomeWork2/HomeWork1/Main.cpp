#include "CH_2_1_1.h"
#include "CH_2_1_2.h"

using namespace CH_2_1;


int main() {


#pragma region 필수 숙제1

    cout << "\n\n\n필수 과제 1 \n\n\n";

    ////템플릿 사용해서 int 로 지정해줬습니다.
    HomeWork_1<int>* work_1 = new HomeWork_1<int>;

    work_1->Push();
    work_1->Plus();
    work_1->average();

    //HomeWork_1<float>* work_2 = new HomeWork_1<float>;

    //work_2->Push();
    //work_2->Plus();
    //work_2->average();

#pragma endregion


    cout << "\n\n\n도전 과제 2 \n\n\n";



   

    BasicSort<int>* st = new CH_2_1::_Sort();
    st->resetCount();
    st->Sort(1);


    cout << "\n\n\n내림차순\n\n\n";
    st->resetCount();
    st->Sort(2);


    cout << "\n\n\n실수 정렬\n\n\n";
    BasicSort<double>* st2 = new Double_Sort();

    st2->resetCount();
    st2->Sort(1);

	return 0;
}