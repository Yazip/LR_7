package com.github.Yazip.LR3;
import java.util.Scanner;
// Класс автор
public class Author implements Writer, Cloneable {
    protected String last_name;
    protected String initials;
    protected String biography;
    protected static int author_count = 0;
    // Конструктор без параметров
    public Author() {
        last_name = "";
        initials = "";
        biography = "";
        ++author_count;
    }
    // Конструктор с 1 параметром
    public Author(String last_name) {
        this.last_name = last_name;
        ++author_count;
    }
    // Конструктор со всеми параметрами
    public Author(String last_name, String initials, String biography) {
        setAuthorData(last_name, initials, biography);
        ++author_count;
    }
    // Сеттер
    public void setAuthorData(String last_name, String initials, String biography) {
        this.last_name = last_name;
        this.initials = initials;
        this.biography = biography;
    }
    // Метод для пользовательского ввода данных
    public void enterAuthorData() {
        Scanner scanner = new Scanner(System.in, "UTF-8");
        System.out.println();
        System.out.println("Введите фамилию автора:");
        last_name = scanner.nextLine();
        System.out.println("Введите инициалы автора:");
        initials = scanner.nextLine();
        System.out.println("Введите биографию автора:");
        biography = scanner.nextLine();
        System.out.println();
        System.out.println("Автор " + last_name + " " + initials + " был успешно создан!");
    }
    // Геттер
    public void getAuthorData() {
        System.out.println();
        System.out.println("Информация об авторе:");
        System.out.println("Фамилия: " + last_name);
        System.out.println("Инициалы: " + initials);
        System.out.println("Биография: " + biography);
    }
    // Геттер для получения фамилии автора
    public String getAuthorLastName() {
        return last_name;
    }
    // Статический геттер для получения кол-ва объектов
    public static int getAuthorCount() {
        return author_count;
    }
    // Реализация метода write() из интерфейса Writer
    @Override
    public void write() {
        System.out.println("Книга написана");
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
}
