//
// Created by Anthony Wong on 2023/5/19.
//
//extern int n;

int fnl(){
    static int n=10;
    n++;
    return n;
}