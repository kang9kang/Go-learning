package main

import "fmt"

func Myfunc() (a int, b int, c int) {
	a, b, c = 1, 2, 3
	return
}

func main() {
	a, b, c := Myfunc()
	fmt.Printf("a=%d,b=%d,c=%d\n", a, b, c)
}
