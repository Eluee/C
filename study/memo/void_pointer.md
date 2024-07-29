# void 포인터에 대하여(void*)

## 역참조 형식지정
void* 는 자료형중의 하나로 어느 하나의 자료형만이 아니라 모든 자료형의 주소값을 저장할 수 있다.
그러나 void* 로 선언된 변수를 **역참조하려면 반드시 형식 지정**을 해줘야한다

```c
    int itarget = 10;
    void* ptmp = &itarget; // ptmp 변수가 itarget의 주소를 참조 
    //ptmp를 역참조하여 itarget의 값을 가져와 출력 
    //int형의 포인터변수로 형변환후 역참조
    printf("%d", *(int *)ptmp); 
```

## %p와 (void*) 형변환의 관계
%p는 포인터변수를 출력하는 형식지정자로 기본적으로 void*형을 기대합니다.
그래서 주소를 출력하고싶을때 마지막에 void* 형으로 바꿔줘야하지만 **명시적으로 적어주지 않아도 자동으로 형변환**해주기 때문에
생략해도 문제는 없습니다.

```c
    int itarget = 10;
    void* ptmp = &itarget;              // ptmp 변수가 itarget의 주소를 참조 
    // 명시적으로 void* 형변환
    printf("%p\n", (void *)ptmp);       // ptmp변수가 역참조시 사용하는 주소를 출력
    printf("%p\n", (void *)&itarget);   // itarget변수의 주소값을 출력

    printf("%p\n", ptmp);       // ptmp변수가 역참조시 사용하는 주소를 출력
    printf("%p\n", &itarget);   // itarget변수의 주소값을 출력
    // 위 두코드의 결과는 동일하다
```

