# Projet INF224 - Vincent Josse

## Questions

### Etape 4:  
La méthode *play()* de la classe *Media* est une **méthode abstraite** déclarée avec le mot clé *virtual* et *= 0;*.    
Elle est redéfinie dans les classes filles.  
On ne peut plus instancier un objet de la classe *Media* parcequ'il s'agit d'une **classe abstraite**.  

### Etape 5:  
La propriété caractéristique de la POO qui permet de traiter tous les objets héritant d'une me classe uniformément est le  **polymorphisme**.
En *C++*, il est nécessaire d'implémenter dans les classes filles (non-abstraites) toutes les méthodes déclarées abstraites dans les classes mères. Le tableau utilisé ici (de type Media \*\*) contient des **pointeurs** vers les les objets (des Media \*). En Java, tous les objets sont des références donc un tableau d'objet est un tableau de références vers les objets.  

### Etape 6:
Pour que l'objet Film ait le plein contrôle de ses données, il faut ne pas copier le pointeur correspondant au tableau mais créer un nouveau tableau à partir du tableau passé en argument sous forme de pointeur en copiant ses données. Ainsi, l'adresse de l'attribut privé de l'objet est différente de celle du tableau passé en argument et ne peut donc pas être modifié à l'extérieur de l'objet. 
Pour éviter des problèmes d'encapsulation dû au getter du tableau de timestamps, il suffit de retourner un const double\* à la place d'un double \*  qui est read-only.
  
### Etape 7:
Puisque l'objet film contient un tableau, si l'on détruit l'objet de manière naïve, seule l'adresse du premier élement du tableau sera supprimée en mémoire. Pour bien faire les choses, il faut demander à delete le contenu du tableau. Pour ce faire, on utilise la directive delete[] timestamps; dans le destructeur de Film.
Pour la copie, il peut y avoir des porblèmes puisque une shallow copy va seulement copier l'adresse du premier élément du tableau et donc casser le principe d'encapsulation. On doit donc faire une deep copy en prenant soin de copier les éléments du tableau timestamps dans le nouvel objet qui seront alloués à une nouvelle adresse, dans un nouveau tableau.

### Etape 8:  
Les pointeurs dans la liste sont nécessaire pour pouvoir faire du polymorphisme. En Java, ce sont toujours des références vers les objets qui sont utilisées.  

### Etape 10:  
On met les méthodes de créations d'objets dans la table en read-only avec le mot clé const.


## Java  
  
### Etape 1:  
Si on ne met pas de scroll bar, au bout de plusieurs appuis sur les boutons, la fenêtre change de taille à chaque fois que l'on rajoute une nouvelle ligne. :S



### Etape 2:  


