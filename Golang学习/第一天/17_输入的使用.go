package main

import "fmt"

func main() {
	var a int
	fmt.Printf("请输入a的值\n")
	// fmt.Scanf("%d", &a)
	fmt.Scan(&a)
	fmt.Printf("a=%d\n", a)
}
