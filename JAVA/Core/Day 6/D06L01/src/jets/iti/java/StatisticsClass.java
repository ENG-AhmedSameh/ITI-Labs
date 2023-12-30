package jets.iti.java;

/*import jets.iti.java.dao.InMemoryWorldDao;
import jets.iti.java.domain.City;
import jets.iti.java.domain.Country;*/

import java.util.*;
import java.util.stream.Collectors;

public class StatisticsClass {
    public static void main(String[] args) {
        InMemoryWorldDao worldInstance = InMemoryWorldDao.getInstance();
        displayCountryHighestPopulatedCity(worldInstance);
        //displayContinentHighestPopulatedCity(worldInstance);
        //displayWorldHighestPopulatedCity(worldInstance);


    }
    public static void displayCountryHighestPopulatedCity(InMemoryWorldDao worldInstance){
        worldInstance.findAllCountries()
                .stream()
                .map(c->c.getCities())
                .map(cityList->cityList.stream().max(Comparator.comparingInt(City::getPopulation)))
                .filter(Optional::isPresent)
                .map(Optional::get)
                .forEach(city -> {
                    System.out.println("Country: "+worldInstance.findCountryByCode(city.getCountryCode()).getName()+", Highest Populated City: "+city.getName());
                });
    }
    public static void displayContinentHighestPopulatedCity(InMemoryWorldDao worldInstance){
        
	Map<String,Optional<City>> continentMaxCity = worldInstance.getAllContinents()
                .stream()
                .collect(Collectors.toMap(
                        contient->contient,
                        contient->worldInstance.findCountriesByContinent(contient)
                                .stream()
                                .filter(country -> !country.getCities().isEmpty())
                                .flatMap(country->country.getCities().stream())
                                .max(Comparator.comparingInt(City::getPopulation))
                ));
        continentMaxCity.forEach(
                (contient,optionalCity)->{
                    System.out.print("Continent: "+contient+", Most Populated City: ");
                    if(optionalCity.isPresent())
                        System.out.println(optionalCity.get().getName());
                    else
                        System.out.println("No Cities in this Continent");
                }
        );
    }
    public static void displayWorldHighestPopulatedCity(InMemoryWorldDao worldInstance){
        worldInstance.findAllCountries()
                .stream()
                .filter(c->!c.getCities().isEmpty())
                .map(c->worldInstance.findCityById(c.getCapital()))
                .max(Comparator.comparingInt(City::getPopulation))
                .ifPresent(maxCity ->
                {
                    System.out.println("City with the max population: " + maxCity.getName());
                });
    }

}
