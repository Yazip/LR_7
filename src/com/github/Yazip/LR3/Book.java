package com.github.Yazip.LR3;
import java.util.Scanner;
// Класс книга
public class Book extends Publication {
    private String author_last_name;
    private String author_initials;
    private String title;
    private String genre_name;
    private int page_count;
    private static int book_count = 0;
    // Конструктор без параметров
    public Book() {
        author_last_name = "";
        author_initials = "";
        title = "";
        genre_name = "";
        page_count = 0;
        ++book_count;
    }
    // Конструктор с 1 параметром
    public Book(String title) {
        this.title = title;
        ++book_count;
    }
    // Конструктор со всеми параметрами
    public Book(String author_last_name, String author_initials, String title, String genre_name, int page_count) {
        setBookData(author_last_name, author_initials, title, genre_name, page_count);
        ++book_count;
    }
    // Сеттер
    public void setBookData(String author_last_name, String author_initials, String title, String genre_name, int page_count) {
        this.author_last_name = author_last_name;
        this.author_initials = author_initials;
        this.title = title;
        this.genre_name = genre_name;
        this.page_count = page_count;
    }
    // Метод для пользовательского ввода данных
    public void enterBookData() {
        Scanner scanner = new Scanner(System.in, "UTF-8");
        System.out.println();
        System.out.println("Введите фамилию автора:");
        author_last_name = scanner.nextLine();
        System.out.println("Введите инициалы автора:");
        author_initials = scanner.nextLine();
        System.out.println("Введите название книги:");
        title = scanner.nextLine();
        System.out.println("Введите название жанра:");
        genre_name = scanner.nextLine();
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
        System.out.println();
        System.out.println("Книга " + title + " была успешно создана!");
    }
    // Геттер
    public void getBookData() {
        System.out.println();
        System.out.println("Информация о книге:");
        System.out.println("Фамилия автора: " + author_last_name);
        System.out.println("Инициалы автора: " + author_initials);
        System.out.println("Название книги: " + title);
        System.out.println("Название жанра: " + genre_name);
        System.out.println("Кол-во страниц: " + page_count);
    }
    // Метод для поиска книг по названию и автору
    public static void findBooksByTitleAndAuthor(Book[] books, String book_title, String author_last_name) {
        Book[] found_books = new Book[300];
        int j = 0;
        for (Book book : books) {
            // Сравнение заданных значений полей и полей из массива книг
            if (((book.title).equalsIgnoreCase(book_title)) && ((book.author_last_name).equalsIgnoreCase(author_last_name))) {
                found_books[j] = book; // Добавление книги в массив найденных книг
                ++j;
            }
        }
        // Вывод найденных книг если они есть
        if (j > 0) {
            System.out.println();
            System.out.println("Найдено " + j + " книг автора " + author_last_name + " с названием \"" + book_title + "\":");
            for (int k = 0; k < j; k++) {
                System.out.println();
                System.out.println("Книга " + (k + 1));
                System.out.println();
                found_books[k].getBookData();
                System.out.println("-------------------------");
            }
        }
        // Иначе вывод сообщения об их отсутствии
        else {
            System.out.println();
            System.out.println("Ничего не найдено!");
        }
    }
    // Метод для поиска книг по автору
    public static void findBooksByAuthor(Book[] books, String author_last_name) {
        Book[] found_books = new Book[300];
        int j = 0;
        for (Book book : books) {
            if ((book.author_last_name).equalsIgnoreCase(author_last_name)) {
                found_books[j] = book;
                ++j;
            }
        }
        if (j > 0) {
            System.out.println();
            System.out.println("Найдено " + j + " книг автора " + author_last_name + ":");
            for (int k = 0; k < j; k++) {
                System.out.println();
                System.out.println("Книга " + (k + 1));
                System.out.println();
                found_books[k].getBookData();
                System.out.println("-------------------------");
            }
        }
        else {
            System.out.println();
            System.out.println("Ничего не найдено!");
        }
    }
    // Метод для поиска книг по жанру
    public static void findBooksByGenre(Book[] books, String genre_name) {
        Book[] found_books = new Book[300];
        int j = 0;
        for (Book book : books) {
            if ((book.genre_name).equalsIgnoreCase(genre_name)) {
                found_books[j] = book;
                ++j;
            }
        }
        if (j > 0) {
            System.out.println();
            System.out.println("Найдено " + j + " книг жанра " + genre_name + ":");
            for (int k = 0; k < j; k++) {
                System.out.println();
                System.out.println("Книга " + (k + 1));
                System.out.println();
                found_books[k].getBookData();
                System.out.println("-------------------------");
            }
        }
        else {
            System.out.println();
            System.out.println("Ничего не найдено!");
        }
    }
    // Статический геттер для получения кол-ва объектов
    public static int getBookCount() {
        return book_count;
    }
    // Геттер для получения жанра книги
    public String getBookGenreName() {
        return genre_name;
    }
    // Переопределение абстрактного метода из базового абстрактного класса
    @Override
    public void read() {
        System.out.println("Книга прочитана");
    }
}