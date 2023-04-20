#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000						// **** do not edit the macro  ****

typedef struct {						// **** do not edit the struct ****
    int film_id;
    char title[255];
    char description[1023];
    unsigned int release_year;
    char rental_duration;
    float rental_rate;
    unsigned char length;
    float replacement_cost;
    char rating[10];
    char last_update[30];
} RECORD_t, *RECORD;

float average_rental_rate(RECORD records){
    float avg_rental_rate=0;
    for (int i = 0; i < 1000; ++i) {
        avg_rental_rate+=records[i].rental_rate;
    }
    avg_rental_rate=avg_rental_rate/1000;
    return avg_rental_rate;
}

float average_release_year(RECORD records){
    float avg_release_year=0;
    for (int i = 0; i < 1000; ++i) {
        avg_release_year+=records[i].release_year;
    }
    avg_release_year= avg_release_year/1000;
    return avg_release_year;
}


//BOZUKKOD
RECORD find_top_ten_films(RECORD records) {
    RECORD toptenFilm = (RECORD) malloc(sizeof(RECORD_t) * 10);
    for (int j = 0; j < 1000; ++j) {
        for (int i = 0; i < 10; ++i) {
            if (records[j].film_id < toptenFilm[i].film_id) {
                toptenFilm[i] = records[j];
                //printf("%s %d ", toptenFilm[i].title,toptenFilm[i].film_id);
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
    }
    return toptenFilm;
}

RECORD find_ten_affordable_films(RECORD records){
    RECORD records2 = (RECORD)malloc(sizeof(RECORD_t) * 10);
    int count=0;
    int i=0;
    while(count != 10) {
        if (average_rental_rate(records) > records[i].rental_rate) {
            if (average_release_year(records) < records[i].release_year) {
                records2[count]=records[i];
                count++;
            }
        }
        i++;
    }
    /*KONTROL MEKANÄ°ZMASI
    for (int x = 0; x < 10; ++x) {
        printf("%s ",records2[x].title);
        printf("%d ",records2[x].release_year);
        printf("%f \n",records2[x].rental_rate);
    }*/
    return records2;
}

int main() {
    // *****************************************************
    // *************** DO NOT EDIT THIS PART ***************
    RECORD records = (RECORD)malloc(sizeof(RECORD_t) * MAX);
    FILE *file = fopen("records.txt", "rb");
    if (file == NULL) {
        printf("Cannot open the file.\n");
        exit(0);
    }
    fread(records, sizeof(RECORD_t) * MAX, 1, file);
    fclose(file);
    // *****************************************************
    // *****************************************************
    printf("Average Rental Rate: %f\n", average_rental_rate(records));
    printf("Average Release Year: %f\n", average_release_year(records));

    RECORD records2;
    records2=find_ten_affordable_films(records);
//DOSYAYA YAZMA
    FILE *file2= fopen("records_affordables.txt","w");
    for (int i = 0; i < 10; ++i) {
        fputs(records2[i].title,file2);
        fputs("\n",file2);
    }
    // *****************************************************
    RECORD topTenFilms=find_top_ten_films(records);
    FILE *file3= fopen("records_top_ten.txt","w");
    //DOSYAYA YAZMA
    for (int i = 0; i < 10; ++i) {
        fputs(topTenFilms[i].title, file3);
        fputs("\n",file3);
    }

    return 1;
}