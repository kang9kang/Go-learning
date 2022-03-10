package main

import "fmt"

func main() {
	defer fmt.Println("aaaaaaaaaa")
	fmt.Println("bbbbbbbbbbb")
}
