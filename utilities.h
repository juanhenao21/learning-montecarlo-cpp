template<typename T>
std::ostream& operator << (std::ostream& os, std::vector<T>& v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        os << v[i] << std::endl;
    }
    return os;
}

struct CompLink
{
    bool operator() (const Link &a, const Link &b)
    {
        return a.source < b.source;
    }
};

struct CompAtom
{
    bool operator() (const Atom &a, const Atom &b)
    {
        return a.id < b.id;
    }
};

