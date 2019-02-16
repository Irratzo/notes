/*
 * Example from Stroustrup_EssenceofC++.org:
 * Find elements with value 'v' in container 'c'
 * using modern C++-style resource management
 */

/*
 * How this works:
 * Return a vector of ptrs to the elts
 * (the value-type of a container is the type of the elts).
 * So, make myself a container to hold the things that match,
 * and then for all x in c, if it's a match, push_back it's address.
 * Pass things by reference cause we don't want copies.
 * Of course, compiling this with C++98 compiler will break.
 */

template<typename C, typename V>
vector<Value_type<C>*>find_all(C& c, V v) //find all occurences of v in c
{
  vector<Value_type<C>*>res;
  for(auto& x : c)              // C++11: find el-type statically from it's
                                // initializer (here, this is the el-type of the container)
    if (x==v)
      res.push_back(&x);        // C++11: 
  return res;                   
}

string m{"Mary had a little lamp"};
for (const auto p:find_all(m,'a')) //p is a char*
  if (*p!='a')                     //for all ptrs that come back from find_all,
    cerr << "string bug!\n";       //test that I actually got the right thing back:
