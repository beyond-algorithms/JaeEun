class Solution:
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        data = {}

        for domain in cpdomains:
            times, url = domain.split()

            self.countDomain(url, times, data)

        return ["%s %s" % (times, url) for url, times in data.items()]

    def countDomain(self, url, times, data):
        subDomains = self.makeSubdomains(url)

        for sub in subDomains:
            data[sub] = data.get(sub, 0) + int(times)

    def makeSubdomains(self, url):
        ret = [url]
        idx = 0

        while True:
            idx = url.find('.', idx + 1)

            if idx == -1:
                return ret

            ret.append(url[idx + 1:])

        # "a.b.c"
        # =>  ["a.b.c", "b.c", "c"]
        # frags = domain.split('.')
        # for i in range(len(frags)):
        #     ans[".".join(frags[i:])] += count
