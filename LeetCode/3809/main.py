class Solution:
    def bestTower(
        self, arr: List[List[int]], center: List[int], radius: int
    ) -> List[int]:
        n = len(arr)
        cx, cy = center[0], center[1]
        temp = []

        for to in arr:
            x, y, quality = to[0], to[1], to[2]
            if abs(x - cx) + abs(y - cy) <= radius:
                temp.append([x, y, quality])

        if not temp:
            return [-1, -1]

        temp.sort(key=lambda x: (x[2], -x[0], -x[1]), reverse=True)

        return [temp[0][0], temp[0][1]]
