package main

import (
	"fmt"
	"os"
)

func main() {
	for i, data := range os.Args {
		fmt.Printf("Args[%d]=%s\n", i, data)
	}
}
