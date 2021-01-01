# Projet INF224 - Vincent Josse

## Questions

### Etape 4:  
La méthode *play()* de la classe *Media* est une **méthode abstraite** déclarée avec le mot clé *virtual* et *= 0;*.    
Elle est redéfinie dans les classes filles.  
On ne peut plus instancier un objet de la classe *Media* parcequ'il s'agit d'une **classe abstraite**.  

### Etape 5:  
La propriété caractéristique de la POO qui permet de traiter tous les objets héritant d'une me classe uniformément est le  **polymorphisme**.
En *C++*, il est nécessaire d'implémenter dans les classes filles (non-abstraites) toutes les méthodes déclarées abstraites dans les classes mères. Le tableau utilisé ici (de type Media \*\*) contient des **pointeurs** vers les les objets (des Media \*). En Java, tous les objets sont des références donc un tableau d'objet est un tableau de références vers les objets.
