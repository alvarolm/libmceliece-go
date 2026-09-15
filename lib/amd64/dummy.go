//go:build dummy

// Package amd64 exists only so that "go mod vendor" copies the files in this
// directory. The "dummy" build tag is never satisfied, so it is never built.
package amd64
