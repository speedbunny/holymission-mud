#define QCM(x) "/d/Ix/obj/cells"->query_icts_main_map()[x]

query_types(n)
{
  switch(QCM(n))
  {
    case "W":
        return 0;
    case "R":
        return 1;
    case "G":
        return 2;
    case "B":
        return 3;
    case "Y":
        return 4;
    case "S":
        return 5;
    default:
        return 3;
  }
}
