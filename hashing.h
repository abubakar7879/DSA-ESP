#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Function to shorten a URL
string shortenURL(string longURL)
{
    static unordered_map<string, string> shortToLongURLs;
    static int counter = 0;

    // If the long URL has already been shortened, return the
    // corresponding short URL
    if (shortToLongURLs.find(longURL) != shortToLongURLs.end())
        return shortToLongURLs[longURL];

    // Otherwise, create a new short URL by hashing the long URL
    string shortURL = "http://tiny.url/" + to_string(counter++);

    // Insert the new short and long URLs into the map
    shortToLongURLs[shortURL] = longURL;

    return shortURL;
}