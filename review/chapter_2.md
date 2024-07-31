# 배열
기본 배열 선언후 초기화 예시 코드
```c
int arr[2] = {1, 2, 3};
```
C의 기본배열은 정적인 구조를 이루고있으며 인댁스를 통해 데이터에 접근한다.
배열의 길이를 적어줘 배열의 크기를 정하고 들어갈 값들을 순차적으로 입력해준다.
데이터는 인덱스 0번부터 순차적으로 왼쪽부터 초기화된다.


다차배열 선언후 초기화 예시코드
```c
int arr[2][2] = {
        {1, 2, 3},
        {4, 6, 9},
        {0, 3, 2}
    };
```
# 함수
함수의 기본선언과 구조
```c
int add(int a, int b){return a + b};
```
위의 함수는 매개변수로 받은 값을 더해서 반환해주는 함수이다. 
위와같이 함수 선언시
**반환자료형 함수명(매개변수자료형 변수명){실행코드 return 반환값};**
규칙으로 만들어진다.

**반환자료형**
함수의 반환자료형에 따라서 함수의 사용법이 달라지는데 
함수의 반환자료형이 void인 경우는 return값이 존재하지 않는다. 
그 외의 자료형일 경우 함수 종료시 return값을 받는다.

**매개변수자료형**
매개변수자료형은 함수를 호출하는 곳에서 함수에게 변수를 넘겨받을때 지정되는 자료형이며 자료형을 맞춰줘야한다. 

기본적으로 Call by value방식으로 작동한다 이말은즉 매개변수로 받은 값이 함수 내부에서 쓰일때 원형 그대로 사용하는게 아닌 복사된 변수를 사용하는게 기본적인 규칙이다. 아래는 예시코드로 알 수 있다.
```c
#include<stdio.h>

void add(int number){
    number += 100;
}

int main(void){
    int number = 100;
    add(number);
    printf("number : %d",number); // number : 100 출력
    return 0;
}
```

변수는 기본적으로 3가지의 종류의 변수가 있다.

1. 자동변수 : 함수 내부에서 선언되며 함수의 반환시 소멸한다 (lifetime 이 존재)
2. 정적변수 : 함수가 반환되더라도 계속해서 존재한다
3. 전역변수 : 함수 외부 전역에 선언되며 다른 함수에서도 접근이 가능하다.

함수 내부에 선언된 변수들은 지역변수 이기 때문에 다른 함수에서 접근할 수 없다. 쓰이는 변수가 서로 다른함수에 선언되어있다면 이름이 같아도 다른메모리를 쓰고 있기 때문에 변수명을 중첩할 수 있다.

**예시코드**
```c
#include <stdio.h>
int globalVar = 0;// 전역변수

void test() {
    // 자동변수
    int autoVar = 0;
    // 정적변수
    static int staticVar = 0;
    // 값 출력
    printf("autoVar: %d, staticVar: %d, globalVar: %d\n",
           autoVar, staticVar, globalVar);
    // 값 증가
    autoVar++;
    staticVar++;
    globalVar++;
}

int main() {
    test();  // 출력: autoVar: 0, staticVar: 0, globalVar: 1
    test();  // 출력: autoVar: 0, staticVar: 1, globalVar: 2
    test();  // 출력: autoVar: 0, staticVar: 2, globalVar: 3

    return 0;
}
```

**순환호출**
함수는 자기자신의 함수나 다른 함수를 호출 할 수 있다. 그러나 함수가 다른함수를 호출하면 그 호출된 함수가 끝나기 전까지
메모리가 반환되지 않기 때문에 순환호출이 길어지면 메모리낭비가 발생한다. 그러므로 적절히 사용해야한다. 

아래는 재귀호출을 사용하여 만든 예제 코드이다.
```c
#include <stdio.h>

void countdown(int n) {
    if (n < 0) {
        printf("Done!\n");
        return;  // 종료 조건
    }
    printf("%d\n", n);
    countdown(n - 1);  // 재귀 호출
}

int main() {
    countdown(5);  // 출력: 5, 4, 3, 2, 1, 0, Done!
    return 0;
}
```

# 포인터
포인터란 메모리 단위로 조작하여 프로그래밍을 효율적으로하기위한 변수이다.
예시코드
```c
 int* ptmp = NULL;
```
위의 예시는 기본적인 int형의 포인터변수를 선언한 예시코드이다.
선언시 자료형 뒤에 *를 붙이는 형태로 사용하며 NULL값으로 초기화하는것이 보편적이다.

포인터변수는 다른변수의 주소값을 저장할 수 있으며 역참조하여 변수에 접근이 가능하다.
아래와 같은 코드가 있다.

```c
int number = 10;
int* pnumber = &number;
```
위와 같이 선언된 pnumber은 &(주소 연산자)를 통해 number의 주소값을 받아서 pnumber에 저장하는 형태로 
pnumber을 역참조할 경우 number에 접근할 수 있다.
주의할점은 역참조하려는 변수의 자료형과 포인터변수의 자료형이 동일해야한다.

**함수의 포인터 사용**
함수의 매개변수에서 포인터 변수를 사용할 수 있다 이방법을 
call by reference 라고 부르며 이방법을 사용하면 다른함수에서도 함수의 원형에 접근하여 읽고 수정하는것이 가능하다.
이를 side effect 라고 부른다.
예시 코드

```c
#include<stdio.h>
void add(int* pnumber){
    *pnumber += 10; // 역참조 후 + 10
}
int main(void){
    int number = 10;
    add(&number);
    printf("number : %d",number); // number : 20 출력
    return 0;
}
```
**함수의 포인터**

함수도 포인터에 저장이 가능하다 포인터를 함수에 저장하려면 선언 규칙을 따라줘야하는데

선언한 함수와 그 함수의 주소를 저장할 포인터변수의 매개변수와 리턴의 형태가 같아야 한다.

만약 선언된함수가 아래와 같다면
```c
    int add(int a, int b){return a + b};
```
main의 포인터 선언은 아래와 같아야한다.
```c
    int (*pfunc)(int, int) = &add;
```


**void 포인터에 대하여(void*)**

**역참조 형식지정**
void* 는 자료형중의 하나로 어느 하나의 자료형만이 아니라 모든 자료형의 주소값을 저장할 수 있다.
그러나 void* 로 선언된 변수를 **역참조하려면 반드시 형변환**을 해줘야한다

```c
    int itarget = 10;
    void* ptmp = &itarget; // ptmp 변수가 itarget의 주소를 참조 
    //ptmp를 역참조하여 itarget의 값을 가져와 출력 
    //int형의 포인터변수로 형변환후 역참조
    printf("%d", *(int *)ptmp); 
```

**%p와 (void*) 형변환의 관계**
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

**배열과 포인터**
배열과 포인터는 서로 유사하지만 다른 개념이다.
배열도 인댁스를 통해 특정 메모리를 가리키고 읽어올 수 있다.
예시코드
```c
int arr[3] = {1, 2, 4};
int* parr = arr;
```
위 코드는 배열 arr를 참조하고 있다.
여기서 arr를 참조할때 &(주소 연산자)를 쓰지 않고 있는데 이는
**배열의 이름은 배열의 첫 요소의 주소값** 이기때문이다.

위와 같이 선언한다면 아래와 같이 역참조가 가능하다
*parr는 arr배열의 첫번째 요소값
아래는 서로 같은 값을 가리킵니다.
- arr[i]
- *(parr + i)

**이중 포인터**
이중 포인터는 포인터가 포인터를 역참조하는 형태로 아래와같은 선언이 가능합니다.
```c
int a = 10;       // 정수형 변수 a
int* ptr = &a;    // 포인터 ptr이 a의 주소를 저장
int** number = &ptr;  // 포인터의 포인터 number가 ptr의 주소를 저장
```
이중 포인터는 포인터변수의 주소값을 저장합며 아래와 역참조시 아래와 같을 수 있습니다.
- ptr : a의 주소값
- *ptr: a의 값
- *number: ptr의 주소값
- **number: a의 값













