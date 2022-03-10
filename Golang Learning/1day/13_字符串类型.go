package main

import "fmt"

func main() {
	var str1 string
	str1 = "abc"
	fmt.Printf("str1=%s\n", str1)

	str2 := "acb"
	fmt.Printf("str2=%T\n", str2)
	fmt.Printf("%d\n", len(str2))

	fmt.Printf("%c,%c\n", str1[0], str1[1])
}
