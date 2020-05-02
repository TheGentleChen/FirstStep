class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> domain_counter;
        vector<string> ret_domains;
        for (auto domain:cpdomains)
        {
            int i = domain.find(" ");
            int num = stoi(domain.substr(0, i));
            string address = domain.substr(i + 1, domain.size() - 1 - i);
            for (int i = address.size() - 1;i >= 0;--i)
            {
                if (address[i] == '.')
                {
                    domain_counter[address.substr(i + 1, address.size() - 1 - i)] += num;
                }
                else if (i == 0)
                {
                    domain_counter[address.substr(0, address.size())] += num;
                }
            }
        }
        for (auto domain:domain_counter)
        {
            ret_domains.push_back(to_string(domain.second) + " " + domain.first);
        }
        return ret_domains;
    }
};
