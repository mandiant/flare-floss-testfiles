package main;

import (
    "fmt";
    "os";
    "bufio";
)

func main() {
    fmt.Print("Enter Password: ");
    user_input,_,err := bufio.NewReader(os.Stdin).ReadLine();
    if err != nil {
            fmt.Println("Something is wrong with your computer, ",err);
    }
    if string(user_input) == "Bugfest" {
        fmt.Println("You Cracked it, A Hero is born");
    } else {
        fmt.Println("Don't Worry, Relax, Chill and Try harder");
    }
}
