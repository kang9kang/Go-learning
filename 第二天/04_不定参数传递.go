package main

import "fmt"

func Myfunc(a ...int) {
	for _, data := range a {
		fmt.Printf("a=%d\n", data)
	}
}

func test(a ...int) {
	Myfunc(a[1:3]...)
}

func main() {
	test(1, 2, 3, 4)
}
