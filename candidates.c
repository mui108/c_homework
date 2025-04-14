#include <stdio.h>
#include <stdlib.h>

#define CANDIDATE_NUM 6
#define INFO_NUM 11
#define MAX_LEN 100

// 후보자 정보 저장용 1차원 배열 6개 (각각 후보 1명, 문자열 11개씩)
char candidate01[INFO_NUM][MAX_LEN];
char candidate02[INFO_NUM][MAX_LEN];
char candidate03[INFO_NUM][MAX_LEN];
char candidate04[INFO_NUM][MAX_LEN];
char candidate05[INFO_NUM][MAX_LEN];
char candidate06[INFO_NUM][MAX_LEN];

// 후보자 배열 포인터 목록
char (*candidate_list[CANDIDATE_NUM])[INFO_NUM][MAX_LEN] = {
    &candidate01, &candidate02, &candidate03,
    &candidate04, &candidate05, &candidate06
};

// 각 정보 항목 이름
const char *member_info[INFO_NUM] = {
    "성명", "생일(YYYY/MM/DD 형식)", "성별(여성이면 F 또는 남성이면 M)",
    "메일 주소", "국적", "BMI", "주 스킬", "보조 스킬",
    "한국어 등급(TOPIK)", "MBTI", "소개"
};

// 생일 포맷 변경 (YYYY/MM/DD → YYYYMMDD)
void format_birth(char *birth) {
    char formatted[MAX_LEN];
    int y, m, d;
    if (sscanf(birth, "%d/%d/%d", &y, &m, &d) == 3) {
        sprintf(formatted, "%04d%02d%02d", y, m, d);
        sprintf(birth, "%s", formatted);
    }
}

// TOPIK 출력 포맷
void print_topik(const char *topik) {
    if (topik[0] == '0') {
        printf("원어민");
    } else {
        printf("%-6s", topik);
    }
}

// 출력용 구분선
void print_line() {
    printf("---------------------------------------------------------------------------------------------\n");
}

int main() {
    int i = 0;

    printf("####################################\n");
    printf("     오디션 후보자 데이터 입력\n");
    printf("####################################\n");

    while (i < CANDIDATE_NUM) {
        printf("후보자 %d의 정보를 입력합니다.\n", i + 1);
        printf("---------------------------------\n");
        for (int j = 0; j < INFO_NUM; j++) {
            printf("%d. %s: ", j + 1, member_info[j]);
            fgets((*candidate_list[i])[j], MAX_LEN, stdin);

            // 개행 문자 제거
            for (int k = 0; (*candidate_list[i])[j][k] != '\0'; k++) {
                if ((*candidate_list[i])[j][k] == '\n') {
                    (*candidate_list[i])[j][k] = '\0';
                    break;
                }
            }

            // 생일 포맷 변환
            if (j == 1) {
                format_birth((*candidate_list[i])[j]);
            }
        }
        printf("=================================\n");
        i++;
    }

    // 출력
    printf("\n####################################\n");
    printf("     오디션 후보자 데이터 조회 \n");
    printf("####################################\n");
    printf("=============================================================================================\n");
    printf("성   명 | 생   일 | 성별 | 메   일            | 국적 | BMI | 주스킬 | 보조스킬 | TOPIK | MBTI |\n");
    printf("=============================================================================================\n");

    for (int i = 0; i < CANDIDATE_NUM; i++) {
        printf("%-6s |%-8s | %-2s | %-18s |%-4s | %-4s | %-6s | %-7s | ",
               (*candidate_list[i])[0], // 이름
               (*candidate_list[i])[1], // 생일
               (*candidate_list[i])[2], // 성별
               (*candidate_list[i])[3], // 메일
               (*candidate_list[i])[4], // 국적
               (*candidate_list[i])[5], // BMI
               (*candidate_list[i])[6], // 주 스킬
               (*candidate_list[i])[7]  // 보조 스킬
        );
        print_topik((*candidate_list[i])[8]); // TOPIK 출력
        printf(" | %-4s |\n", (*candidate_list[i])[9]); // MBTI
        print_line();
        printf("%s\n", (*candidate_list[i])[10]); // 소개
        print_line();
    }

    printf("............................................ (이하 생략)...........................\n");

    return 0;
}
