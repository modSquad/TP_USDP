#!/usr/bin/env python
# -*- coding: utf-8 -*-

from xml.dom.minidom import parse, parseString

def getText(nodelist):
	rc = []
	for node in nodelist:
		if node.nodeType == node.TEXT_NODE:
			rc.append(node.data)
	return ''.join(rc)

dom = parse('data.xml')

needs = dom.getElementsByTagName('b')
parsedNeeds = []

for n in needs:
	domains = n.getElementsByTagName('d')
	titles = n.getElementsByTagName('t')

	for d in domains:
		print getText(d.childNodes)

	for t in titles:
		print getText(t.childNodes)

