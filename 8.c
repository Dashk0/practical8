#include <stdio.h>
#include <string.h>

// Функція для обміну значень двох символів
void swap(char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Рекурсивна функція для генерації анаграм
void generateAnagrams(char *word, int start, int end, int *count) {
    int i;
    if (start == end) {
        // Вивести анаграму
        printf("%s\n", word);
        (*count)++;
    } else {
        for (i = start; i <= end; i++) {
            // Зробити обмін з першим символом
            swap((word + start), (word + i));
            // Рекурсивно генерувати анаграми для підрядкового рядка
            generateAnagrams(word, start + 1, end, count);
            // Повернути початковий порядок
            swap((word + start), (word + i));
        }
    }
}

int main() {
    char word[15];
    int count = 0;
    
    // Ввід слова
    printf("Введіть слово: ");
    scanf("%s", word);
    
    int length = strlen(word);
    
    // Виклик рекурсивної функції для генерації анаграм
    generateAnagrams(word, 0, length - 1, &count);
    
    // Виведення кількості анаграм
    printf("Кількість анаграм: %d\n", count);
    
    return 0;
}
