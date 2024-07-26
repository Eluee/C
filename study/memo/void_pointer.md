# void 포인터에 대하여(void*)

void* 는 자료형중의 하나로 어느 하나의 자료형만이 아니라 모든 자료형의 주소값을 저장할 수 있다.
그러나 void* 로 선언된 변수를 **역참조하려면 반드시 형식 지정**을 해줘야한다

```c
    int itarget = 10;
    void* ptmp = &itarget; // ptmp 변수가 itarget의 주소를 참조 
    //ptmp를 역참조하여 itarget의 값을 가져와 출력 
    //int형의 포인터변수로 형변환후 역참조
    printf("%d", *(int *)ptmp); 
```