package com.github.Yazip.LR3;
import java.util.Scanner;
// Класс журнал
public class Magazine extends Publication{
    private String publisher_name;
    private String title;
    private String frequency;
    private int page_count;
    private float price;
    private static int magazine_count = 0;
    // Конструктор без параметров
    public Magazine() {
        publisher_name = "";
        title = "";
        frequency = "";
        page_count = 0;
        price = 0.0f;
        ++magazine_count;
    }
    // Конструктор с 1 параметром
    public Magazine(String title) {
        this.title = title;
        ++magazine_count;
    }
    // Конструктор со всеми параметрами
    public Magazine(String publisher_name, String title, String frequency, int page_count, float price) {
        setMagazineData(publisher_name, title, frequency, page_count, price);
        ++magazine_count;
    }
    // Сеттер
    public void setMagazineData(String publisher_name, String title, String frequency, int page_count, float price) {
        this.publisher_name = publisher_name;
        this.title = title;
        this.frequency = frequency;
        this.page_count = page_count;
        this.price = price;
    }
    // Метод для пользовательского ввода данных
    public void enterMagazineData() {
        Scanner scanner = new Scanner(System.in, "UTF-8");
        System.out.println();
        System.out.println("Введите название издателя:");
        publisher_name = scanner.nextLine();
        System.out.println("Введите название журнала:");
        title = scanner.nextLine();
        System.out.println("Введите периодичность:");
        frequency = scanner.nextLine();
        System.out.println("Введите кол-во страниц (не меньше 0):");
        do {
            while (!scanner.hasNextInt()) {
                System.out.println("Ошибка. Введите корректное число:");
                scanner.next();
            }
            page_count = scanner.nextInt();
            if (page_count < 0) {
                System.out.println("Ошибка. Введите кол-во страниц не меньше 0:");
            }
        } while (page_count < 0);
        System.out.println("Введите цену (не меньше 0):");
        do {
            while (!scanner.hasNextFloat()) {
                System.out.println("Ошибка. Введите корректную цену:");
                scanner.next();
            }
            price = scanner.nextFloat();
            if (price < 0.0f) {
                System.out.println("Ошибка. Введите цену не меньше 0:");
            }
        } while (price < 0.0f);
        System.out.println();
        System.out.println("Журнал " + title + " был успешно создан!");
    }
    // Геттер
    public void getMagazineData() {
        System.out.println();
        System.out.println("Информация о журнале:");
        System.out.println("Издатель: " + publisher_name);
        System.out.println("Название журнала: " + title);
        System.out.println("Периодичность: " + frequency);
        System.out.println("Кол-во страниц: " + page_count);
        System.out.println("Цена: " + price);
    }
    // Метод для поиска журналов по издателю
    public static void findMagazinesByPublisher(Magazine[] magazines, String publisher_name) {
        Magazine[] found_magazines = new Magazine[300];
        int j = 0;
        for (Magazine magazine : magazines) {
            if ((magazine.publisher_name).equalsIgnoreCase(publisher_name)) {
                found_magazines[j] = magazine;
                ++j;
            }
        }
        if (j > 0) {
            System.out.println();
            System.out.println("Найдено " + j + " журналов издателя " + publisher_name + ":");
            for (int k = 0; k < j; k++) {
                System.out.println();
                System.out.println("Журнал " + (k + 1));
                System.out.println();
                found_magazines[k].getMagazineData();
                System.out.println("-------------------------");
            }
        }
        else {
            System.out.println();
            System.out.println("Ничего не найдено!");
        }
    }
    // Статический геттер для получения кол-ва объектов
    public static int getMagazineCount() {
        return magazine_count;
    }
    // Переопределение абстрактного метода из базового абстрактного класса
    @Override
    public void read() {
        System.out.println("Журнал прочитан");
    }
}
