/**
  * Touhou Community Reliant Automatic Patcher
  * Cheap command-line patch stack configuration tool
  *
  * ----
  *
  * Repository handling.
  */

#pragma once

// Returns the local file name of a repository file as a JSON string.
json_t* RepoGetLocalFN(const char *id);

// Starts repository discovery at [start_url], recurses through all neighbors
// and downloads any repository files found in the process.
// [url_cache] and [id_cache] are used to detect duplicate URLs and repos.
// These can be NULL if the caller doesn't intend to keep these caches.
int RepoDiscover(const char *start_url, json_t *id_cache, json_t *url_cache);

// Loads repository files from all subdirectories of the current directory,
// then calls RepoDiscover() with [url_cache] on their server URLs.
// Returns a JSON object in the following format:
// {
//	"<repository ID>": {
//		<contents of repo.js>
//	},
//	...
// }
json_t* RepoLoadLocal(json_t *url_cache);
