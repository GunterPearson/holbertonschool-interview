#!/usr/bin/python3
"""Count it module"""
import requests


def count_words(subreddit, word_list, after=None, count={}):
    """Count words in word_list in subreddit"""
    if after is None:
        url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    else:
        url = 'https://www.reddit.com/r/{}/hot.json?after={}'.format(
            subreddit, after)
    subreddit_req = requests.get(url,
                                 headers={"user-agent": "user"},
                                 allow_redirects=False)
    try:
        data = subreddit_req.json().get("data")
    except Exception as e:
        return None
    for word in word_list:
        word = word.lower()
        if word not in count.keys():
            count[word] = 0
    children = data.get("children")
    for child in children:
        top = (child.get("data").get("title").lower())
        top = top.split(' ')
        for word in word_list:
            word = word.lower()
            count[word] += top.count(word)
    after = data.get("after")
    if after is None:
        sorted_subs = sorted(count.items(), key=lambda x: (-x[1], x[0]))
        for i in sorted_subs:
            if i[1] != 0:
                print(i[0] + ": " + str(i[1]))
    else:
        return count_words(subreddit, word_list, after, count)
