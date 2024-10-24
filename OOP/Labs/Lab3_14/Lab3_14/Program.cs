using System;
using System.Collections.Generic;
using Lab3_14;
Queue queue1 = new Queue();
queue1  += 5;
queue1  += 15;
queue1  += 10;
queue1.Print();
queue1 --;
queue1.Print();

Queue queue2 = new Queue();
queue2 = queue2 + 3;
queue2 = queue2 + 8;
queue2.Print();

Queue mergedQueue = queue1 < queue2;
mergedQueue.Print();

Console.WriteLine(StatisticOperation.sum(mergedQueue));
Console.WriteLine(StatisticOperation.diff(mergedQueue));
Console.WriteLine(StatisticOperation.count(mergedQueue));
int qq = queue1;
Console.WriteLine(qq);  



