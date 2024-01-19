package com.github.Yazip.LR3;
import java.util.Scanner;
// Класс жанр
public class Genre implements Cloneable {
    private String name;
    private String description;
    private Author[] authors;
    private static int genre_count = 0;
    // Конструктор без параметров
    public Genre() {
        name = "";
        description = "";
        ++genre_count;
    }
    // Конструктор с 1 параметром
    public Genre(String name) {
        this.name = name;
        ++genre_count;
    }
    // Конструктор со всеми параметрами
    public Genre(String name, String description) {
        setGenreData(name, description);
        ++genre_count;
    }
    // Сеттер
    public void setGenreData(String name, String description) {
        this.name = name;
        this.description = description;
    }
    // Метод для пользовательского ввода данных
    public void enterGenreData() {
        Scanner scanner = new Scanner(System.in, "UTF-8");
        System.out.println();
        System.out.println("Введите название жанра:");
        name = scanner.nextLine();
        System.out.println("Введите описание жанра:");
        description = scanner.nextLine();
        System.out.println();
        System.out.println("Жанр " + name + " был успешно создан!");
    }
    // Геттер
    public void getGenreData() {
        System.out.println();
        System.out.println("Информация о жанре:");
        System.out.println("Название: " + name);
        System.out.println("Описание: " + description);
        if (authors != null) {
            System.out.println("Авторы, пишущие в этом жанре:");
            for (int i = 0; i < authors.length; i++) {
                authors[i].getAuthorData();
            }
        }
    }
    public void setAuthors(Author[] authors) {
        this.authors = new Author[authors.length];
        for (int i = 0; i < authors.length; i++) {
            this.authors[i] = (Author) authors[i].clone();
        }
    }
    // Статический геттер для получения кол-ва объектов
    public static int getGenreCount() {
        return genre_count;
    }
    // Замена метода Display перегрузкой toString
    @Override
    public String toString() {
        return "\nНазвание: " + name + "\nОписание: " + description + "\n";
    }
    // Переопределение метода clone() для поддержки клонирования
    @Override
    public Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            throw new AssertionError();
        }
    }
    // Метод для мелкого клонирования
    public Genre shallowClone() {
        return (Genre) this.clone();
    }
    // Метод для глубокого клонирования
    public Genre deepClone() {
        Genre genre_clone = (Genre) this.clone();
        if (this.authors != null) {
            genre_clone.authors = new Author[this.authors.length];
            for (int i = 0; i < this.authors.length; i++) {
                genre_clone.authors[i] = (Author) this.authors[i].clone();
            }
        }
        return genre_clone;
    }
}
