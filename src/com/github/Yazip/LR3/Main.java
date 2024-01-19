package com.github.Yazip.LR3;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
public class Main {
    public static void main(String[] args) {
        Author author1 = new Author("Шукшин", "В.М.", "Родился...");
        Author author2 = new Author("Шолохов", "М.А.", "Родился...");
        AuthorTranslator authorTranslator1 = new AuthorTranslator("Маршак", "С.Я.", "Родился...", "Английский");
        AuthorTranslator authorTranslator2 = new AuthorTranslator("Чуковский", "К.И.", "Родился...", "Английский");

        List<Author> authorList = new ArrayList<>();
        authorList.add(author1);
        authorList.add(author2);
        authorList.add(authorTranslator1);
        authorList.add(authorTranslator2);

        Collections.sort(authorList, Comparator.comparing(Author::getAuthorLastName));

        System.out.println("Отсортированный по фамилиям по алфавиту контейнер с объектами классов Author и AuthorTranslator:");
        for (Author author : authorList) {
            author.getAuthorData();
        }

        String searchLastName = "Шолохов";
        Author foundAuthor = authorList.stream()
                .filter(author -> author.getAuthorLastName().equals(searchLastName))
                .findFirst()
                .orElse(null);

        if (foundAuthor != null) {
            System.out.println("\nАвтор найден:");
            foundAuthor.getAuthorData();
        } else {
            System.out.println("\nАвтор не найден.");
        }
        new Scanner(System.in).nextLine();
    }
}