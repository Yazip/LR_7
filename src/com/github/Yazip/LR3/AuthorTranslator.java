package com.github.Yazip.LR3;
import java.util.Scanner;
// Класс автор-переводчик, наследник класса автор
public class AuthorTranslator extends Author{
    private String languages;
    // Конструктор без параметров
    public AuthorTranslator() {
        super();
        languages = "";
    }
    // Конструктор с 1 параметром
    public AuthorTranslator(String last_name) {
        super(last_name);
    }
    // Конструктор со всеми параметрами
    public AuthorTranslator(String last_name, String initials, String biography, String languages) {
        super(last_name, initials, biography);
        this.languages = languages;
    }
    // Сеттер
    public void setAuthorTranslatorData(String last_name, String initials, String biography, String languages) {
        super.setAuthorData(last_name, initials, biography);
        this.languages = languages;
    }
    // Метод для пользовательского ввода данных
    public void enterAuthorTranslatorData() {
        Scanner scanner = new Scanner(System.in, "UTF-8");
        System.out.println();
        System.out.println("Введите фамилию автора:");
        last_name = scanner.nextLine();
        System.out.println("Введите инициалы автора:");
        initials = scanner.nextLine();
        System.out.println("Введите биографию автора:");
        biography = scanner.nextLine();
        System.out.println("Введите языки, которые используются автором-переводчиком:");
        languages = scanner.nextLine();
        System.out.println();
        System.out.println("Автор-переводчик " + last_name + " " + initials + " был успешно создан!");
    }
    // Геттер (перегрузка метода базового класса с вызовом метода базового класса)
    public void getAuthorTranslatorData() {
        super.getAuthorData();
        System.out.println("Языки: " + languages);
    }
    // Геттер (перегрузка метода базового класса без вызова метода базового класса)
    @Override
    public void getAuthorData() {
        System.out.println();
        System.out.println("Информация об авторе:");
        System.out.println("Фамилия: " + last_name);
        System.out.println("Инициалы: " + initials);
        System.out.println("Биография: " + biography);
        System.out.println("Языки: " + languages);
    }
}
