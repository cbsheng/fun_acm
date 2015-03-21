import cookielib, urllib2, re, sys, HTMLParser, os.path
 
PHPSESSID = "siysh7m83gd9sdqf87smz38r2jujz62p"
 
def saveFileByType(code_content, parser, languages=[], postfixes=[]):
  for index, language in enumerate(languages):
    code_pattern = re.compile("""scope\.code\."""+language+""" = '.*?'""")
    matched_code = code_pattern.search(code_content)
    if(matched_code != None):
      matched_code = matched_code.group(0)
      code = matched_code.split("'")[1]
      code = code.decode('unicode_escape')
      title_pattern = re.compile("""/problems/.*</a></h4>""")
      matched_title = title_pattern.search(code_content).group(0)
      title = matched_title[matched_title.index('>')+1:matched_title.index('<')]
      filename = "".join([title, "." + postfixes[index]])
      if os.path.isfile(filename) == False:
        myFile = open(filename, 'w')
        myFile.write(code)
        myFile.close()
        print "".join(["File saved with filename: ", title, "." + postfixes[index]])
 
cj = cookielib.CookieJar()
opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))
parser = HTMLParser.HTMLParser()
 
opener.addheaders = [
    ('User-Agent', 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/31.0.1650.63 Safari/537.36'),
    ('Referer', 'http://oj.leetcode.com/accounts/login/'),
    ('Cookie', 'PHPSESSID=' + PHPSESSID + '; _ga=GA1.2.1984831265.1389075465; NRAGENT=tk=26e67c3be080fab2'),
    ]
 
 
for i in range(1,500):
  page = 'http://oj.leetcode.com/submissions/' + `i`
  print page
  resp = opener.open(page)
  content = resp.read()
  error_pattern = re.compile("No more submissions.")
  if error_pattern.search(content) is not None:
    print "Program finished with all your submissions have been saved"
    sys.exit()
  url_pattern = re.compile("[0-9]*/\"><strong>Accepted</strong></a>")
  for match in url_pattern.findall(content):
    url = "".join(["http://oj.leetcode.com/submissions/detail/", match.split('/')[0]])
    resp = opener.open(url)
    code_content = resp.read()
    saveFileByType(code_content, parser, ["java", "python", "cpp"], ["java", "py", "cpp"])