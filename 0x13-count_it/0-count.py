#!/usr/bin/python3
"""Count it module"""
import requests


def count_words(subreddit, word_list, after='', counter=None):
    """count words"""
    if counter is None:
        counter = {item: 0 for item in word_list}

    if after is None:
        items = counter.items()
        sorted_items = sorted(items, key=lambda x: x[1])[::-1]
        for (key, value) in sorted_items:
            if value != 0:
                print("{}: {}".format(key, value))
        return None
    url = "https://www.reddit.com/r/{}/hot/.json".format(subreddit)
    params = {'after': after, 'limit': 100}
    done = requests.get(url, params=params, allow_redirects=False)

    if done.status_code == 200:
        done = done.json()
        after = done["data"]["after"]
        children = [child for child in done["data"]["children"]]
        for child in children:
            title = child["data"]["title"]
            tokens = [token.lower() for token in title.split()]
            for word in word_list:
                counter[word] += tokens.count(word)

        count_words(subreddit, word_list, after, counter)
    else:
        return None
