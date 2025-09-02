#include<stdio.h>          //기본 입출력을 위한 라이브러리
#include<time.h>        // 게임에 시간흐름을 나타내기 위한 라이브러리
#include<stdlib.h>      //난수를 발생시키기 위한 라이브러리

/*
   컴퓨터가 만든 임의의 숫자 ( 1 ~ 100 )를 플레이어가 맞추는 게임

   컴퓨터는 임의 숫자를 결정하고
   플레이어는 숫자를 입력하고 임의의 숫자보다 낮으면 "High than" 라고 출력,
   임의의 숫자보다 크면 "Low than" 라고 출력
   같으면 맞았습니다 라고 출력함.

   이때 숫자를 몇번에 맞췄는지 출력함
*/


int main(void)
{
	int com;
	int player;
	int count = 0;

	srand(time(NULL));

	// 컴퓨터는 임의 숫자를 결정하고
	com = rand() % 100 + 1;

	while (1)
	{
		count++;
		printf("숫자를 입력하세요 ( 1 ~ 100 )\n");
		// 플레이어는 숫자를 입력하고
		scanf_s("%d", &player);

		// 임의의 숫자보다 낮으면 "High than" 라고 출력
		if (player < com)
		{
			printf("High than \n");
		}

		// 임의의 숫자보다 크면 "Low than" 라고 출력
		else
		{
			if (player > com)
			{
				printf("Low than \n");
			}

			// 	같으면 맞았습니다 라고 출력
			// 이때 숫자를 몇번에 맞췄는지 출력
			else
			{
				printf("%d 번째에 맞았습니다. \n", count);
			}
		}

	}



	system("pause");
	return 0;

}
