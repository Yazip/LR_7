package com.github.Yazip.LR3;
import java.util.Scanner;
// Класс издатель
public class Publisher<T> {
    private String name;
    private String address;
    private T phone_num;
    private String email;
    private static int publisher_count = 0;
    // Конструктор без параметров
    public Publisher() {
        name = "";
        address = "";
        email = "";
        ++publisher_count;
    }
    // Конструктор с 1 параметром
    public Publisher(String name) {
        try {
            if (name.isEmpty()) {
                throw new IllegalArgumentException("Название не может быть пустым");
            }
            this.name = name;
            ++publisher_count;
        }
        catch (IllegalArgumentException e) {
            System.out.println("Некорректный аргумент: " + e.getMessage());
        }
    }
    // Конструктор со всеми параметрами
    public Publisher(String name, String address, T phone_num, String email) {
        setPublisherData(name, address, phone_num, email);
        ++publisher_count;
    }
    // Сеттер
    public void setPublisherData(String name, String address, T phone_num, String email) {
        this.name = name;
        this.address = address;
        this.phone_num = phone_num;
        this.email = email;
    }
    // Геттер
    public void getPublisherData() {
        System.out.println();
        System.out.println("Информация об издателе:");
        System.out.println("Название: " + name);
        System.out.println("Адрес: " + address);
        System.out.println("Номер телефона: " + phone_num);
        System.out.println("Электронная почта: " + email);
    }
    public static int getPublisherCount() {
        return publisher_count;
    }
}
