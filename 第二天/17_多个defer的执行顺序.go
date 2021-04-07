package main

import "fmt"

func main() {
	defer fmt.Println("aaaaaaaaa")
	defer fmt.Println("bbbbbbbbb")
	defer fmt.Println("ccccccccc")
}
