package main

import (
	"cala"
	"fmt"
)

func Test() {
	a, b := 10, 20
	fmt.Println(cala.Add(a, b))
	fmt.Println(cala.Minus(a, b))
}
