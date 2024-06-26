# What is this?

This creates a basic RESTful web service using a JSON file as source.

# Usage

This script uses python's own HTTPServer. Just run it from the command line, like so:

`$ ./instant-api.py`

To specify the port and/or file to serve, just use the `--port` and `--file` attributes, respectively:

`$ ./instant-api.py --port 8080 --file source.json`

This script uses the `friendlier/path/format` and can go several levels deep in the JSON, with support for arrays.

# Example

Given this JSON:

```json
{
	"colors" : [
		{
			"name" : "Red",
			"hex" : "#FF0000"
		},
		{
			"name" : "Green",
			"hex" : "#00FF00"
		},
		{
			"name" : "Blue",
			"hex" : "#0000FF"
		}
	]
}
```

You could use this:

`http://localhost:8080/colors/1`

To retrieve this:

```json
{
	"name" : "Green",
	"hex" : "#00FF00"
}
```

# Licensing and Contact

MIT License.
