from collections import defaultdict


class Solution:
    def ladderLength(self, start: str, end: str, words: List[str]) -> int:
        if end not in words:
            return 0

        word_set = set(words)
        vis = set([start])
        n = len(start)

        buckets = defaultdict(list)
        for word in words:
            for i in range(n):
                pattern = word[:i] + "_" + word[i + 1 :]
                buckets[pattern].append(word)

        def is_neighbor(a, b):
            return sum(x != y for x, y in zip(a, b)) == 1

        def layered_bfs(layer, depth):
            if not layer:
                return 0

            next_layer = set()
            for word in layer:
                if is_neighbor(word, end):
                    return depth + 1

                # This gives TLE
                # for w in word_set:
                #     if w not in vis and is_neighbor(word, w):
                #         vis.add(w)
                #         next_layer.add(w)

                for i in range(n):
                    pattern = word[:i] + "_" + word[i + 1 :]
                    for nei in buckets[pattern]:
                        if nei not in vis:
                            vis.add(nei)
                            next_layer.add(nei)

            return layered_bfs(next_layer, depth + 1)

        return layered_bfs({start}, 1)
