package com.github.Yazip.LR3;
public class BookManager {
    public static int countBooksByGenre(Book[] books, String genre_name) {
        int count = 0;
        for (Book book : books) {
            if ((book.getBookGenreName()).equalsIgnoreCase(genre_name)) {
                count++;
            }
        }
        return count;
    }
}
