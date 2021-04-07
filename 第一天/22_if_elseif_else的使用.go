package main

import "fmt"

func main() {
	// a := 11
	// if a == 10 {
	// 	fmt.Println("a==10")
	// } else {
	// 	fmt.Println("a!=10")
	// }

	if a := 11; a == 10 {
		fmt.Println("a==10")
	} else if a > 10 {
		fmt.Println("a>10")
	}
}
