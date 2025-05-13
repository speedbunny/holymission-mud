#define QCO "/players/kbl/cloud/clmap"->query_cloud_overlay()

query_accden(n)
{
  switch(QCO[n])
  {
    case "Z":
    case "R":
        return ({6,12,6,9});
    case "G":
        return ({1,5,1,5});
    case "B":
        return ({15,21,11,18});
    case "Y":
        return ({10,17,8,13});
    case "W":
        return ({1,21,1,18});
    case "S":
        return ({20,50,16,45});
    case "H":
        return ({35,50,28,45});
    default:
        return ({1,5,1,5});
  }
}

/* Format of above array positions:

            0 = min access
            1 = max access
            2 = min density
            3 = max density

*/
