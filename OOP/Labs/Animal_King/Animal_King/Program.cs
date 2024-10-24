// See https://aka.ms/new-console-template for more information
using Animal_King;


Player user = new Player("bobric", 0, 0, 15);
Lion lion1 = new Lion("lionchick", 0, 1, 0);
Console.WriteLine(lion1.HP);
user.AttackSword(ref lion1.ConvertToAnimal());
Console.WriteLine(lion1.HP);
Bird owl = new Bird("ddd", 1, 0, 34);
