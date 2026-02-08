from heapq import heappush, heappop
from collections import defaultdict
from typing import List


class Twitter:
    def __init__(self):
        self.time = 0
        self.following = defaultdict(set)
        self.tweets = defaultdict(list)

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.tweets[userId].append((self.time, tweetId))
        self.time += 1

    def getNewsFeed(self, userId: int) -> List[int]:
        heap = []

        users = self.following[userId] | {userId}

        for uid in users:
            if self.tweets[uid]:
                time, tid = self.tweets[uid][-1]
                idx = len(self.tweets[uid]) - 1
                heappush(heap, (-time, tid, uid, idx))

        res = []
        while heap and len(res) < 10:
            _, tid, uid, idx = heappop(heap)
            res.append(tid)

            if idx > 0:
                time, tid = self.tweets[uid][idx - 1]
                heappush(heap, (-time, tid, uid, idx - 1))

        return res

    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId != followeeId:
            self.following[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        self.following[followerId].discard(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
