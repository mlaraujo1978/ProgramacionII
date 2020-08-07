package edu.utn;

import edu.utn.beverage.Beverage;
import edu.utn.beverage.Coffee;
import edu.utn.beverage.Tea;
import edu.utn.condiment.CondimentDecorator;
import edu.utn.condiment.Milk;
import edu.utn.condiment.Sugar;

public class Main {

    public static void main(String[] args) {


        Beverage cafe = new Coffee();
        CondimentDecorator cafeConLeche = new Milk(cafe);
        cafeConLeche.printBeverageInfo();

        Beverage te = new Tea();
        CondimentDecorator TeConAzucar = new Sugar(te);
        TeConAzucar.printBeverageInfo();

        CondimentDecorator TeConLeche = new Milk(te);
        TeConLeche.printBeverageInfo();
    }
}
