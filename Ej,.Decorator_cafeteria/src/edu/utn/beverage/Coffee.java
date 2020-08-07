package edu.utn.beverage;

import edu.utn.beverage.Beverage;

public class Coffee extends Beverage {


    @Override
    public String getDescription() {
        return "Coffee";
    }

    @Override
    public float getPrice() {
        return (float) 104.5;
    }

    @Override
    public void printBeverageInfo() {

    }
}
