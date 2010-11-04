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

domains = dom.getElementsByTagName('d')

for d in domains:
	title = getText(d.getElementsByTagName('t')[0])

	groups = dom.getElementsByTagName('gr')
	for g in groups:
		name = getText(g.getElementsByTagName('n')[0])
		cases = g.getElementsByTagName('c')
		parsedCases = []

		for c in cases:
			parsedCases.append(c.childNodes)

		print name, ':', parsedCases
