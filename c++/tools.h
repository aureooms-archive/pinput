#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vector){
	out << "[";
	if(!vector.empty()){
		for (size_t index = 0; index < vector.size()-1; ++index){
			out << vector[index];
			out << ", ";
		}
		out << vector[vector.size()-1];
	}
	out << "]";
	return out;
}

template<typename Key, typename T>
std::ostream& operator<<(std::ostream& out, const std::unordered_map<Key,T>& map){
	out << "{";
	if (map.size() > 0){
		typename std::unordered_map<Key,T>::const_iterator it;
		size_t i = 0;
		for(it = map.begin(); i < map.size()-1; ++it, ++i){
			out << it->first;
			out << " : ";
			out << it->second;
			out << ", ";
		}
		out << it->first;
		out << " : ";
		out << it->second;
	}
	out << "}";
	return out;
}

template<typename Key>
std::ostream& operator<<(std::ostream& out, const std::unordered_set<Key>& set){
	out << "{";
	if (set.size() > 0){
		typename std::unordered_set<Key>::const_iterator it;
		size_t i = 0;
		for(it = set.begin(); i < set.size()-1; ++it, ++i){
			out << *it;
			out << ", ";
		}
		out << *it;
	}
	out << "}";
	return out;
}

#endif //TOOLS_H
