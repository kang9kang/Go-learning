package main

import "fmt"

func Myfunc01(a ...int) {
	fmt.Println("len(a)=", len(a))
	for i := 0; i < len(a); i++ {
		fmt.Printf("a[%d]=%d\n", i, a[i])
	}
	for i, data := range a {
		fmt.Printf("a[%d]=%d\n", i, data)
	}
}

func main() {
	Myfunc01()
	Myfunc01(1)
	Myfunc01(1, 2, 3)
}
